#include "ns3/log.h"
#include "ns3/packet.h"

#include "connector.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("Connector");

namespace dcn {

NS_OBJECT_ENSURE_REGISTERED (Connector);

TypeId
Connector::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::dcn::Connector")
      .SetParent<Object> ()
      .SetGroupName ("DCN")
  ;
  return tid;
}

Connector::~Connector ()
{
  NS_LOG_FUNCTION (this);
}

void
Connector::SetSendTarget (SendTargetCallback cb)
{
  NS_LOG_FUNCTION (this);
  m_sendTarget = cb;
}

Connector::SendTargetCallback
Connector::GetSendTarget (void)
{
  return m_sendTarget;
}

void
Connector::SetDropTarget (DropTargetCallback cb)
{
  NS_LOG_FUNCTION (this);
  m_dropTarget = cb;
}

Connector::DropTargetCallback
Connector::GetDropTarget (void)
{
  return m_dropTarget;
}

void
Connector::Receive (Ptr<Packet> p)
{
  NS_LOG_FUNCTION (this);
  DoReceive (p);
}

void
Connector::DoDispose (void)
{
  NS_LOG_FUNCTION (this);
  m_sendTarget.Nullify ();
  m_dropTarget.Nullify ();
  Object::DoDispose ();
}

void
Connector::Send (Ptr<Packet> p)
{
  NS_LOG_FUNCTION (this << p);
  m_sendTarget (p);
}

void
Connector::Drop (Ptr<Packet> p)
{
  NS_LOG_FUNCTION (this << p);
  m_dropTarget (p);
}

}
}