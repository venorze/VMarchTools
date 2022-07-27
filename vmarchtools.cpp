/* AUTHOR: TIAN_SHENG, DATE: 2022/7/27 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvarargs"

#include "vmarchtools.h"
#include <cstdio>
#include <stdexcept>
#include <cstdarg>

namespace vmarchtools {

    std::string vfmt(const std::string &__fmt, va_list __va)
    {
        char *buf;
        int len;
        len = vasprintf(&buf, __fmt.c_str(), __va);
        std::string __fmtret(buf, len);
        free(buf);

        return __fmtret;
    }

    std::string fmt(const std::string &__fmt, ...)
    {
        va_list va;
        va_start(va, __fmt);
        std::string __fmtret = vfmt(__fmt, va);
        va_end(va);

        return __fmtret;
    }

    void verror(const std::string &__fmt, ...)
    {
        va_list va;
        va_start(va, __fmt);
        throw std::runtime_error(vfmt(__fmt, va));
        va_end(va);
    }

    void printf_to_stdout(const std::string &__fmt, ...)
    {
        va_list va;
        va_start(va, __fmt);
        fprintf(stdout, "%s", vfmt(__fmt, va).c_str());
        va_end(va);
    }

    void printf_to_stderr(const std::string &__fmt, ...)
    {
        va_list va;
        va_start(va, __fmt);
        fprintf(stderr, "%s", vfmt(__fmt, va).c_str());
        va_end(va);
    }

}

#pragma clang diagnostic pop