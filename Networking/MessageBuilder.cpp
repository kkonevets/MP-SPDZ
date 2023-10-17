#include <cstdint>
#include <type_traits>

#include "MessageBuilder.h"

#include "Tools/octetStream.h"
#include "GC/Thread.h"
#include "Networking/PlayerCtSocket.h"
#include "OT/OTMultiplier.h"
#include "Processor/ThreadJob.h"
#include "Tools/octetStream.h"
#include "BMR/AndJob.h"
#include "Tools/FlexBuffer.h"
#include "Yao/YaoGarbler.h"
#include "Yao/YaoEvalWire.h"

template <>
void serialize<int>(const int&, uint8_t*)
{}

template <>
int deserialize<int>(uint8_t*)
{
    return 0;
}

template <>
void serialize<string>(const string&, uint8_t*)
{}

template <>
string deserialize<string>(uint8_t*)
{
    return "";
}

template <>
void serialize<MultJob>(const MultJob&, uint8_t*)
{}

template <>
MultJob deserialize<MultJob>(uint8_t*)
{
    return MultJob();
}

template <>
void serialize<ThreadJob>(const ThreadJob&, uint8_t*)
{}

template <>
ThreadJob deserialize<ThreadJob>(uint8_t*)
{
    return ThreadJob();
}

template <>
void serialize<GC::ScheduleItem>(const GC::ScheduleItem&, uint8_t*)
{}

template <>
GC::ScheduleItem deserialize<GC::ScheduleItem>(uint8_t*)
{
    return GC::ScheduleItem();
}


template <>
void serialize<PlayerCtSocket::Pack>(const PlayerCtSocket::Pack&, uint8_t*)
{}

template <>
PlayerCtSocket::Pack deserialize<PlayerCtSocket::Pack>(uint8_t*)
{
    return PlayerCtSocket::Pack();
}

template <>
void serialize<octetStream*>(octetStream* const&, uint8_t*)
{}

template <>
octetStream* deserialize<octetStream*>(uint8_t*)
{
    return new octetStream;
}

template <>
void serialize<octetStream const*>(octetStream const* const&, uint8_t*)
{}

template <>
octetStream const* deserialize<octetStream const*>(uint8_t*)
{
    return new octetStream;
}

// =============================== Not gear ============================

template <>
void serialize<AndJob*>(AndJob* const&, uint8_t*)
{}

template <>
AndJob* deserialize<AndJob*>(uint8_t*)
{
    return new AndJob;
}

template <>
void serialize<std::shared_ptr<SendBuffer>>(
    std::shared_ptr<SendBuffer> const&, uint8_t*)
{}

template <>
std::shared_ptr<SendBuffer> deserialize<std::shared_ptr<SendBuffer>>(uint8_t*)
{
    return std::make_shared<SendBuffer>();
}

template <>
void serialize<YaoAndJob<YaoGarbleWire>*>(
    YaoAndJob<YaoGarbleWire>* const&, uint8_t*)
{}

template <>
YaoAndJob<YaoGarbleWire>* deserialize<YaoAndJob<YaoGarbleWire>*>(uint8_t*)
{
    return nullptr;
}

template <>
void serialize<YaoAndJob<YaoEvalWire>*>(
    YaoAndJob<YaoEvalWire>* const&, uint8_t*)
{}

template <>
YaoAndJob<YaoEvalWire>* deserialize<YaoAndJob<YaoEvalWire>*>(uint8_t*)
{
    return nullptr;
}
