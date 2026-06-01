#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp[100];
    int count = 0;
    int choice, id, i, found;

    while(1) {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &emp[count].id);

                printf("Enter Employee Name: ");
                scanf("%s", emp[count].name);

                printf("Enter Salary: ");
                scanf("%f", &emp[count].salary);

                count++;
                printf("Employee Added Successfully!\n");
                break;

            case 2:
                for(i = 0; i < count; i++) {
                    printf("\nID: %d", emp[i].id);
                    printf("\nName: %s", emp[i].name);
                    printf("\nSalary: %.2f\n", emp[i].salary);
                }
                break;

            case 3:
                printf("Enter Employee ID: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < count; i++) {
                    if(emp[i].id == id) {
                        printf("\nEmployee Found\n");
                        printf("Name: %s\n", emp[i].name);
                        printf("Salary: %.2f\n", emp[i].salary);
                        found = 1;
                    }
                }

                if(found == 0)
                    printf("Employee Not Found\n");

                break;

            case 4:
                printf("Enter Employee ID: ");
                scanf("%d", &id);

                for(i = 0; i < count; i++) {
                    if(emp[i].id == id) {
                        printf("Enter New Salary: ");
                        scanf("%f", &emp[i].salary);
                        printf("Salary Updated Successfully!\n");
                    }
                }
                break;

            case 5:
                printf("Enter Employee ID: ");
                scanf("%d", &id);

                for(i = 0; i < count; i++) {
                    if(emp[i].id == id) {

                        int j;
                        for(j = i; j < count - 1; j++) {
                            emp[j] = emp[j + 1];
                        }

                        count--;
                        printf("Employee Deleted Successfully!\n");
                        break;
                    }
                }
                break;

            case 6:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}