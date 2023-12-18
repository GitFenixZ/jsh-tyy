#include "utils.h"
#include "../src/internals.h"
#include "test_core.h"
#include <assert.h>
#include <fcntl.h>

void handle_command_call_test(command_call *actual, command_call *expected, int line, const char *file,
                              test_info *info) {
    info->total++;

    int failed = info->failed;

    handle_int_test(actual->argc, expected->argc, line, file, info);

    if (failed != info->failed) {
        info->failed++;
        return;
    }

    for (size_t i = 0; i < actual->argc; i++) {
        handle_string_test(actual->argv[i], expected->argv[i], line, file, info);
        if (failed != info->failed) {
            info->failed++;
            return;
        }
    }

    handle_int_test(actual->background, expected->background, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    handle_int_test(actual->stdin, expected->stdin, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    handle_int_test(actual->stdout, expected->stdout, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    handle_int_test(actual->stderr, expected->stderr, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    info->passed++;
}

void handle_command_result_test(command_result *actual, command_result *expected, int line, const char *file,
                                test_info *info) {
    info->total++;

    int failed = info->failed;

    handle_int_test(actual->exit_code, expected->exit_code, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    handle_command_call_test(actual->call, expected->call, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    info->passed++;
}

void handle_job_test(job *actual, job *expected, int line, const char *file, test_info *info) {
    info->total++;

    int failed = info->failed;

    handle_int_test(actual->id, expected->id, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    handle_int_test(actual->pid, expected->pid, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    handle_int_test(actual->last_status, expected->last_status, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    handle_int_test(actual->type, expected->type, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    handle_command_call_test(actual->command, expected->command, line, file, info);
    if (failed != info->failed) {
        info->failed++;
        return;
    }

    info->passed++;
}

command_result *mute_command_execution(command_call *command_call) {
    int fd = open("/dev/null", O_WRONLY);
    assert(fd != -1);
    int old_stdout = dup(STDOUT_FILENO);
    assert(old_stdout != -1);
    dup2(fd, STDERR_FILENO);

    command_result *result = execute_command_call(command_call);

    dup2(old_stdout, STDOUT_FILENO);

    close(fd);
    close(old_stdout);

    return result;
}
