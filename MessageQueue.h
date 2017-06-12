#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <cstdint>
#include <string>
#include <system_error>
#include <vector>

namespace mq
{

struct Attributes
{
    enum Permissions : std::uint8_t
    {
        ReadOnly, WriteOnly, ReadWrite
    };
    std::uint64_t maxMessages;
    std::uint64_t maxMessageSize;
    Permissions access;
};

class MessageQueueError : public std::system_error
{
public:
    using std::system_error::system_error;
};

class IMessageQueueReceiver
{
public:
    virtual ~IMessageQueueReceiver() noexcept = default;
    virtual void Receive(std::vector<std::uint8_t>& buffer, std::size_t length) const noexcept(false) = 0;
};

class IMessageQueueSender
{
public:
    virtual ~IMessageQueueSender() noexcept = default;
    virtual void Send(const std::vector<std::uint8_t>& buffer) const noexcept(false) = 0;
};

class MessageQueue
{
public:
    MessageQueue() = default;
    MessageQueue(const MessageQueue&) = delete;
    MessageQueue(MessageQueue&&) noexcept = delete;
    MessageQueue& operator=(const MessageQueue&) = delete;
    MessageQueue& operator=(MessageQueue&&) noexcept = delete;
    virtual ~MessageQueue() noexcept = 0;  // Virtual destructor makes the class abstract

protected:
    void Create(const std::string& queueName, const Attributes& attributes) noexcept(false);
    void Connect(const std::string& queueName, Attributes::Permissions accessRights) noexcept(false);
    void Subscribe(const std::string& queueName) noexcept(false);
    void Send(const std::vector<std::uint8_t>& buffer) const noexcept(false);
    void Receive(std::vector<std::uint8_t>& buffer, std::size_t length) const noexcept(false);
    void Close() noexcept(false);
    void Remove() noexcept(false);

private:
    void CheckErrors(int returnCode) const noexcept(false);
    void CheckErrors(ssize_t value) const noexcept(false);
    int ConvertToFlag(Attributes::Permissions accessRights) const noexcept(false);

    using mqd_t = std::int32_t;
    std::string m_queueName {};
    mqd_t m_mq {-1};
};

}

#endif //MESSAGEQUEUE_H
