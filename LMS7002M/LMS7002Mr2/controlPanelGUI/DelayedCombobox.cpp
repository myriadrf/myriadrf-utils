#include "DelayedCombobox.h"

#include <iostream>
using namespace std;

DelayedCombobox::DelayedCombobox(wxWindow *parent, wxWindowID id,
                                 const wxString& value,
                                 const wxPoint& pos,
                                 const wxSize& size,
                                 int n , const wxString choices[],
                                 long style,
                                 const wxValidator& validator,
                                 const wxString& name)
    : wxChoice(parent, id, pos, size, n, choices, style, validator, name)
{
    m_initialized = false;
    m_defaultIndex = -1;
}

DelayedCombobox::DelayedCombobox(wxWindow *parent, wxWindowID id,
                                 const wxPoint& pos,
                                 const wxSize& size,
                                 int n , const wxString choices[],
                                 long style,
                                 const wxValidator& validator,
                                 const wxString& name)
    : wxChoice(parent, id, pos, size, n, choices, style, validator, name)
{
    m_initialized = false;
    m_defaultIndex = -1;
}

int DelayedCombobox::Append(const wxString &str)
{
    int pos = m_strings.size();
    m_strings.push_back(str);
    return pos;
}

void DelayedCombobox::Append(const wxArrayString &sarray)
{
    for(unsigned int i=0; i<sarray.size(); ++i)
        m_strings.push_back(sarray[i]);
}

void DelayedCombobox::Clear()
{
    m_initialized = false;
    wxChoice::Clear();
    m_strings.clear();
    m_defaultIndex = -1;
}

void DelayedCombobox::SetSelection(int n)
{
    if(!m_initialized)
    {
        m_defaultIndex = n;
        wxChoice::Clear();
        if(m_defaultIndex < m_strings.size() )
            wxChoice::Append(m_strings[m_defaultIndex]);
        else
            wxChoice::Append("error setting default values");
        wxChoice::SetSelection(0);
    }
    else
        wxChoice::SetSelection(n);
}

int DelayedCombobox::GetSelection() const
{
    if(!m_initialized)
        return m_defaultIndex;
    else
        return wxChoice::GetSelection();
}

void DelayedCombobox::SetDefaultValues(wxArrayString &strings, int defaultSelection)
{
    m_initialized = false;
    m_strings.reserve( strings.size() );
    for(unsigned int i=0; i<strings.size(); ++i)
        m_strings.push_back(strings[i]);
    m_defaultIndex = defaultSelection;
    wxChoice::Clear();
    wxChoice::Append(m_strings[defaultSelection]);
    wxChoice::SetSelection(0);
}

void DelayedCombobox::OnFocusGot(wxFocusEvent& event)
{
    Initialize();

    event.Skip();
}

void DelayedCombobox::Initialize()
{
    if(m_initialized)
        return;
    m_initialized = true;
    Freeze();
    wxChoice::Clear();
    //cout << "\t\tinitializing delayed combobox" << endl;
    wxChoice::Append(m_strings);
    wxChoice::SetSelection(m_defaultIndex);
    Thaw();
}


BEGIN_EVENT_TABLE(DelayedCombobox, wxChoice)
    //EVT_CHAR(DelayedCombobox::OnChar)
    //EVT_KEY_DOWN(DelayedCombobox::OnKeyDown)
    //EVT_KEY_UP(DelayedCombobox::OnKeyUp)
    EVT_ERASE_BACKGROUND(DelayedCombobox::OnEraseBackGround)
    EVT_SET_FOCUS(DelayedCombobox::OnFocusGot)
END_EVENT_TABLE()
