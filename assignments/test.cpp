char is_name_correct(char name[50]) {
    // check for character validity
    for (char i = 0; i < strlen(name); i++) {
        if (!(name[i] == 32 || (name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122))) {
            RETURN = 1;
            break;
        }
    }

    return !RETURN;
}