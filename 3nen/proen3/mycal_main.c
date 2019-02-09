int main(int argc, char *argv[]){
    switch(argc){
        case 3:
            cal2(*(argv+1), *(argv+2));
            break;
        default:
            calhelp();
            break;
    }

    return 0;
}
