#ifndef GUARD_LoopbackPacketSender
#define GUARD_LoopbackPacketSender

class LoopbackPacketSender {
private:
    virtual ~LoopbackPacketSender();
public:
    void send(void*);
};

#endif