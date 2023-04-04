#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    uid_t real_uid = getuid();
    uid_t effective_uid = geteuid();
    gid_t real_gid = getgid();
    gid_t effective_gid = getegid();
    struct passwd *real_pw = getpwuid(real_uid);
    struct passwd *effective_pw = getpwuid(real_uid);
    struct group *real_group = getgrgid(real_gid);
    struct group *effective_group = getgrgid(effective_gid);
    printf("Reel\t\t: %s(UID:%d), %s(GID:%d)\n", real_pw->pw_name, real_uid, real_group->gr_name, real_gid);
    printf("Effectif\t: %s(UID:%d), %s(GID:%d)\n", effective_pw->pw_name, effective_uid, effective_group->gr_name, effective_gid);
}