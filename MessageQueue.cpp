#include <mqueue.h>
#include <sys/fcntl.h>
#include <iostream>
#include "MessageQueue.h"

namespace mq
{

MessageQueue::~MessageQueue() noexcept {}

void MessageQueue::Create(const std::string& queueName, const Attributes& attributes) noexcept(false)
{
    mq_attr attrs {0, static_cast<long int>(attributes.maxMessages), static_cast<long int>(attributes.maxMessageSize), 0};
    int mqd = mq_open(queueName.c_str(), O_CREAT | ConvertToFlag(attributes.access), 0644, &attrs);
    CheckErrors(mqd);

    m_queueName = queueName;
    m_mq = mqd;
}

void MessageQueue::Connect(const std::string &queueName, Attributes::Permissions accessRights) noexcept(false)
{
    int mqd = mq_open(queueName.c_str(), ConvertToFlag(accessRights));
    CheckErrors(mqd);

    m_queueName = queueName;
    m_mq = mqd;
}

void MessageQueue::Subscribe(const std::string& queueName) noexcept(false)
{
    Connect(queueName, Attributes::ReadOnly);
}

void MessageQueue::Receive(std::vector<std::uint8_t>& buffer, std::size_t length) const noexcept(false)
{
    ssize_t received {mq_receive(m_mq, reinterpret_cast<char*>(buffer.data()), length, nullptr)};
    CheckErrors(received);
}

void MessageQueue::Send(const std::vector<std::uint8_t>& buffer) const noexcept(false)
{
    int ret {mq_send(m_mq, reinterpret_cast<const char*>(buffer.data()), buffer.size(), 0)};
    CheckErrors(ret);
}

void MessageQueue::Close() noexcept(false)
{
    CheckErrors(mq_close(m_mq));
}

void MessageQueue::Remove() noexcept(false)
{
    CheckErrors(mq_unlink(m_queueName.c_str()));
}

void MessageQueue::CheckErrors(int returnCode) const noexcept(false)
{
    if (returnCode == -1)
        throw MessageQueueError{errno, std::generic_category()};
}

void MessageQueue::CheckErrors(ssize_t value) const noexcept(false)
{
    if (value == -1)
        throw MessageQueueError{errno, std::generic_category()};
}

int MessageQueue::ConvertToFlag(Attributes::Permissions accessRights) const noexcept(false)
{
    switch (accessRights)
    {
        case Attributes::ReadOnly:
            return O_RDONLY;
        case Attributes::WriteOnly:
            return O_WRONLY;
        case Attributes::ReadWrite:
            return O_RDWR;
        default:
            throw std::out_of_range{"Incorrect value of Attributes::Permissions passed."};
    }
}

}
