#include "MessageQueueServer.h"
#include <cstdint>
#include <vector>

int main()
{
    mq::MessageQueueServer server{"/mqserverexample", mq::Attributes{10, 5, mq::Attributes::ReadWrite}};
    std::vector<std::uint8_t> buf {1, 2, 3, 4, 5};
    while (true)
    {
        server.Send(buf);
    }
    return 0;
}
