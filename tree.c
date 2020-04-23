/*
** EPITECH PROJECT, 2020
** Fir Tree
** File description:
** Function that displays a fir tree, based on its given size.
If the size is 0, doesn't display anything.
*/
void my_putchar(char);
//int my_getnbr(char *s);
//void my_putstr(char *str);

int calculate_min_leafs(int tree_size){
    int min_leafs;
    int times;

    times = 0;
    min_leafs = 0;
    switch(tree_size){
    case 1:
        min_leafs = 1;
        break;
    default:
        min_leafs = tree_size*2 + calculate_min_leafs(tree_size-1);
        times = (tree_size-2)/2;
        while(times>0){
            min_leafs -=2;
            times--;
        }
    }
    return (min_leafs);
}

int calculate_max_leafs(int tree_size){
    int max_leafs, times;

    max_leafs = 0;
    times = 0;
    switch(tree_size){
        case 1:
            max_leafs = 7;      
            break;
        default:
            max_leafs = calculate_max_leafs(tree_size-1) + 6 ;
            times = ((tree_size+1)/2)-1;
            while(times>0){
                max_leafs +=2;
                times--;
            }
    }
    return (max_leafs);
}

int calculate_writing_point(int tree_size){
    return (calculate_max_leafs(tree_size)/2);
}

void write_trunk(int tree_size){
    int  trunk_width, trunk_height;
    int writing_point;
    
    trunk_height = tree_size;
    trunk_width = tree_size;
    writing_point = calculate_writing_point(tree_size);
    if(tree_size%2 == 0){
        trunk_width = tree_size + 1;            
    }
    for(int i=0 ; trunk_width/2 > i; i++){
        writing_point--;
    }
    for(int b_h = 0; b_h < trunk_height; b_h++){
        for(int k = 0; k < writing_point; k++){
            my_putchar(' ');
        }
        for(int b_w = 0; b_w < trunk_width; b_w++ ){
            my_putchar('|');
        }
        my_putchar('\n');
    }
}

int write_leafs(int tree_size, int writing_point){
    int leafs, current_rows, initial_leafs, maximum_leafs, times;
    current_rows = tree_size+3;
    if(tree_size == 1){
        leafs = 1;    
        for(int i = 0; i < current_rows; i++){
            for(int k = 0; k < writing_point; k++){
                my_putchar(' ');
            }
            for(int j = 0; j<leafs; j++){
                my_putchar('*');
            }
            writing_point--;
            my_putchar('\n');
            leafs += 2;
        } 
        writing_point += 2;    
    }else{
        writing_point = write_leafs(tree_size-1, writing_point);
        initial_leafs = calculate_min_leafs(tree_size);
        maximum_leafs = calculate_max_leafs(tree_size);
        for(int i = 0; i < current_rows; i++){
            for(int k = 0; k < writing_point; k++){
                my_putchar(' ');
            }
            for(int j = 0; j<initial_leafs; j++){
                my_putchar('*');
            }
            writing_point--;
            my_putchar('\n');
            initial_leafs += 2;
        }
        //Calculate writing point.
        times = (calculate_max_leafs(tree_size) - calculate_min_leafs(tree_size+1))/2;
        while(times>0){
            writing_point+=1;
            times--;
        }
        writing_point++;
    }
    return(writing_point);
}

void tree(int tree_size){
    int writing_point;
    if(tree_size <= 0){
        //my_putstr("The argument must be positive.\n");
    }else{
        writing_point = calculate_writing_point(tree_size);
        write_leafs(tree_size, writing_point);
        write_trunk(tree_size);
    }
}
/*
int main(int argc, char **argv){
    if(argc == 1){
        //printf("Error, no arguments were introduced.\n");
        return (1);
    }else{
        if(argc > 2){
            //  printf("Error, too many arguments.\n");
            return(1);
        }else{
            argv++;
            tree(my_getnbr(*argv));
        }
    }
    return (0);
}
*/
