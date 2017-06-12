#include "MessageQueueSubscriber.h"

namespace mq
{

MessageQueueSubscriber::MessageQueueSubscriber(const std::string &queueName) : MessageQueue{}
{
    Subscribe(queueName);
}

void MessageQueueSubscriber::Receive(std::vector<std::uint8_t>& buffer, std::size_t length) const
{
    MessageQueue::Receive(buffer, length);
}

}