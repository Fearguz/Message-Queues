#include "MessageQueueSubscriber.h"
#include <iostream>

int main(int, char**)
{
    try
    {
        mq::MessageQueueSubscriber sub{"/mqserverexample"};
        std::vector<std::uint8_t> buffer(5, 0U);
        while (true)
        {
            sub.Receive(buffer, buffer.size());
            std::cout << "Received..." << std::endl;
            for (auto& e : buffer)
            {
                std::cout << (int)e << " ";
            }
            std::cout << std::endl;
        }
    }
    catch (mq::MessageQueueError& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
