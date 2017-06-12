#include "MessageQueueServer.h"
#include <mqueue.h>

namespace mq
{

MessageQueueServer::MessageQueueServer(const std::string& queueName, const Attributes& attrs) : MessageQueue{}
{
    Create(queueName, attrs);
}

MessageQueueServer::~MessageQueueServer() noexcept
{
    try
    {
        Close();
        Remove();
    }
    catch (const MessageQueueError& e)
    {
        // Nothing to do.
    }
}

void MessageQueueServer::Receive(std::vector<std::uint8_t>& buffer, std::size_t length) const noexcept(false)
{
    MessageQueue::Receive(buffer, length);
}

void MessageQueueServer::Send(const std::vector<std::uint8_t>& buffer) const noexcept(false)
{
    MessageQueue::Send(buffer);
}

}
