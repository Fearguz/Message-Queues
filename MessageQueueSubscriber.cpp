#include "MessageQueueSubscriber.h"

namespace mq
{

MessageQueueSubscriber::MessageQueueSubscriber(const std::string &queueName) : MessageQueue{}
{
    Subscribe(queueName);
}

MessageQueueSubscriber::~MessageQueueSubscriber() noexcept
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

void MessageQueueSubscriber::Receive(std::vector<std::uint8_t>& buffer, std::size_t length) const
{
    MessageQueue::Receive(buffer, length);
}

}