// -----------------------------------------------------------------------------
// FILE: 		SignalHandler.cpp
// DESCRIPTION: class used for passing messages between modules
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#include "SignalHandler.h"

/** @brief SignalHandler
*/
SignalHandler::SignalHandler()
{
    m_listeners.clear();
}

/** @brief ~SignalHandler
*/
SignalHandler::~SignalHandler()
{}

/** @brief RegisterForNotifications
    @param handler Signal handler to add for notifications
*/
void SignalHandler::RegisterForNotifications(SignalHandler* handler)
{
    if(handler == this)
        return;

    for(unsigned i=0; i<m_listeners.size(); ++i)
    {
        if(m_listeners[i] == handler)
            return;
    }

    m_listeners.push_back(handler);
}

/** @brief UnregisterFromNotifications
    @param handler Signal handler to remove from listeners list
*/
void SignalHandler::UnregisterFromNotifications(SignalHandler* handler)
{
    for(unsigned i=0; i<m_listeners.size(); ++i)
    {
        if(m_listeners[i] == handler)
        {
            m_listeners.erase(m_listeners.begin()+i);
        }
    }
}

/** @brief Sends given message to all registered signal handlers
    @param msg Message about event
*/
void SignalHandler::Notify(const LMS_Message& msg)
{
    for(unsigned i=0; i<m_listeners.size(); ++i)
    {
        m_listeners[i]->HandleMessage(msg);
    }
}
