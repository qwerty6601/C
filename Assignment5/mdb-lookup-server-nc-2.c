#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void die(const char *s)
{
    perror(s);
    exit(1);
}

int main () {

    while (1){

        pid_t pid;
        while ((pid = waitpid((pid_t)-1, NULL, WNOHANG)) > 0) { // WNOHANG means waitpid() non-blocking
            fprintf(stderr, "[pid=%d] ", (int) pid);
            fprintf(stderr, "mdb-lookup-server terminated\n");
        }

        printf("port number: ");
        char port[100];

        if (fgets(port, sizeof(port), stdin) == NULL)
            break;
        printf("%send", port);

        if (port[0] == '\n')
            continue;
        int x;
        sscanf(port, "%d", &x); // get int from port String

        pid = fork();

        if (pid < 0) {
            die("fork failed");
        } else if (pid == 0) {
            fprintf(stderr, "mdb-lookup-server started on port %s\n", port);
            execl("./mdb-lookup-server-nc.sh", "mdb-lookup-server-nc.sh",
                  port, (char *)0);
            die("execl failed");
        }
        // ??how to clear port buffer here (not needed for this lab but gen question)
    }
    return 0;

}

