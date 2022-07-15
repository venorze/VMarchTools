/* AUTHOR: TIAN_SHENG, DATE: 2022/7/13 */
#include "vmarchcmd.h"

/* 定义命令执行函数 */
#define VMARCH_DEFINE_CMD_CALL(name) \
    void vmarchcmd_exec_##name(const struct vmarch_option_flags *)

VMARCH_API VMARCH_DEFINE_CMD_CALL(start);
VMARCH_API VMARCH_DEFINE_CMD_CALL(stop);

/* 通过宏定义去调用命令 */
#define vmarch_cmd_exec(name, p_optflags) vmarchcmd_exec_##name(p_optflags)

/* 执行命令 */
void vmarchcmd_exec(const struct vmarch_option_flags *p_optflags)
{
    if (p_optflags->cmd & VMARCHCMD_START)
        vmarch_cmd_exec(start, p_optflags);

    if (p_optflags->cmd & VMARCHCMD_STOP)
        vmarch_cmd_exec(stop, p_optflags);
}