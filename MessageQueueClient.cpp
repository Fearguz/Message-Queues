#include "MessageQueueClient.h"

namespace mq
{

MessageQueueClient::MessageQueueClient(const std::string &queueName) : MessageQueue{}
{
    MessageQueue::Connect(queueName, Attributes::WriteOnly);
}

MessageQueueClient::~MessageQueueClient() noexcept
{
    try
    {
        Close();
    }
    catch (const MessageQueueError& e)
    {
        // Nothing to do.
    }
}

void MessageQueueClient::Send(const std::vector<std::uint8_t>& buffer) const
{
    MessageQueue::Send(buffer);
}

}