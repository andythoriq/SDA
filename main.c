#include "nbtree.h"

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Create Tree\n");
    printf("2. Pre-order Traversal\n");
    printf("3. In-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("5. Level-order Traversal\n");
    printf("6. Print Tree\n");
    printf("7. Search Character\n");
    printf("8. Count Elements\n");
    printf("9. Count Leaf Nodes\n");
    printf("10. Exit\n");
}

int main() {
    Isi_Tree tree;
    int choice, num_nodes;
    char search_char;

    while (true) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &num_nodes);
            NbTree_Create(tree, num_nodes);
            break;
        case 2:
            NbTree_PreOrder(tree);
            break;
        case 3:
            NbTree_InOrder(tree);
            break;
        case 4:
            NbTree_PostOrder(tree);
            break;
        case 5:
            NbTree_LevelOrder(tree);
            break;
        case 6:
            NbTree_Print(tree);
            break;
        case 7:
            printf("Enter character to search: ");
            scanf(" %c", &search_char);
            if (NbTree_Search_char(tree, search_char)) {
                printf("Character '%c' found in the tree.\n", search_char);
            } else {
                printf("Character '%c' not found in the tree.\n", search_char);
            }
            break;
        case 8:
            printf("Total elements in the tree: %d\n",
                   NbTree_CountElement(tree));
            break;
        case 9:
            printf("Total leaf nodes in the tree: %d\n",
                   NbTree_CountLeaf(tree));
            break;
        case 10:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}