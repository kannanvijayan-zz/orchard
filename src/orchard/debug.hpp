#ifndef ORCHARD__DEBUG_HPP
#define ORCHARD__DEBUG_HPP

#include "common.hpp"

namespace Orchard {


#if defined(ENABLE_DEBUG)

#define ORCH_ASSERT_IF(pre, cond) \
    do { \
        if (pre) \
            ::Orchard::Assert(__FILE__, __LINE__, #pre " => " #cond, cond); \
    } while(false)
#define ORCH_ASSERT(cond) \
    ::Orchard::Assert(__FILE__, __LINE__, #cond, cond)
void Assert(const char *file, int line, const char *condstr, bool cond);

#define ORCH_UNREACHABLE(msg) \
    ::Orchard::AssertUnreachable(__FILE__, __LINE__, msg)
void AssertUnreachable(const char *file, int line, const char *msg);

template <typename T>
class DebugVal
{
  private:
    T val_;

  public:
    DebugVal() : val_() {}
    DebugVal(const T &val) : val_(val) {}

    operator const T &() const {
        return val_;
    }
};


#else // !defined(ENABLE_DEBUG)

#define ORCH_ASSERT_IF(pre, cond)
#define ORCH_ASSERT(cond)
#define ORCH_UNREACHABLE(msg)

template <typename T>
class DebugVal
{
  public:
    DebugVal() {}
    DebugVal(const T &val) {}
};


#endif // defined(ENABLE_DEBUG)


} // namespace Orchard

#endif // ORCHARD__DEBUG_HPP
