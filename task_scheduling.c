#include <stdio.h>

struct Task {
    int id, start, finish;
};

// schedule tasks greedily
void schedule_tasks(struct Task tasks[], int n) {
    // sort by finish time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tasks[j].finish > tasks[j + 1].finish) {
                struct Task t = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = t;
            }
        }
    }

    printf("Selected tasks:\n");
    int last_finish = 0;
    for (int i = 0; i < n; i++) {
        if (tasks[i].start >= last_finish) {
            printf("Task %d: start %d, finish %d\n", tasks[i].id, tasks[i].start, tasks[i].finish);
            last_finish = tasks[i].finish;
        }
    }
}

int main() {
    int n;
    struct Task tasks[100];
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    printf("Enter start and finish time for each task:\n");
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        scanf("%d %d", &tasks[i].start, &tasks[i].finish);
    }

    schedule_tasks(tasks, n);
    return 0;
}
