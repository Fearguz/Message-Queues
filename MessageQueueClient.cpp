#include "MessageQueueClient.h"

namespace mq
{
MessageQueueClient::MessageQueueClient(const std::string &queueName) : MessageQueue{}
{
    MessageQueue::Connect(queueName, Attributes::WriteOnly);
}

void MessageQueueClient::Send(const std::vector<std::uint8_t>& buffer) const
{
    MessageQueue::Send(buffer);
}

}