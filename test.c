#include <linux/init.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

SYSCALL_DEFINE1(test, int, cmd)
{
        struct task_struct *task = current;
        uid_t uid = current_uid().val;
        pid_t pid = task->pid;

        pr_err("[X] Adding System Call Test\n");
        pr_err("[+] Current PID : %d, UID : %d\n", pid, uid);

        return 0;
}