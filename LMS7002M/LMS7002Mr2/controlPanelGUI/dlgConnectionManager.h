// -----------------------------------------------------------------------------
// FILE: 		dlgConnectionManager.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef DLGCONNECTIONMANAGER_H
#define DLGCONNECTIONMANAGER_H

//(*Headers(dlgConnectionManager)
#include <wx/dialog.h>
class wxStaticLine;
class wxRadioBox;
class wxListBox;
class wxStaticText;
class wxFlexGridSizer;
class wxButton;
//*)

class ConnectionManager;

class dlgConnectionManager: public wxDialog
{
public:
    dlgConnectionManager(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    void SetConnectionManager(ConnectionManager *pManager);
    virtual ~dlgConnectionManager();

    //(*Declarations(dlgConnectionManager)
    wxStaticText* StaticText2;
    wxButton* btnCancel;
    wxListBox* listTransmitters;
    wxRadioBox* rgrControlDevice;
    wxStaticText* StaticText1;
    wxButton* btnOK;
    wxStaticLine* StaticLine2;
    wxListBox* listReceivers;
    wxStaticLine* StaticLine1;
    wxButton* btnDisconnect;
    //*)

protected:

    //(*Identifiers(dlgConnectionManager)
    static const long ID_CONTROLDEVICE_RGR;
    static const long ID_STATICTEXT1;
    static const long ID_STATICLINE1;
    static const long ID_STATICTEXT2;
    static const long ID_LISTBOX1;
    static const long ID_STATICLINE2;
    static const long ID_LISTBOX2;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    //*)

private:
    ConnectionManager *m_pManager;
    //(*Handlers(dlgConnectionManager)
    void OnbtnOKClick(wxCommandEvent& event);
    void OnbtnCancelClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnbtnDisconnectClick(wxCommandEvent& event);
    //*)

protected:
    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);
    DECLARE_EVENT_TABLE()
};

#endif
