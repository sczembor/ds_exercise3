struct getval{
    int res;
    string val1<>;
    int val2;
    float val3;
};

program COM{
    version COMVER{
        int innit() = 1;
        int set_value(string key<>, string val1<>, int val2, float val3) =2;
        getval get_value(string key<>) = 3;
        int modify_value(string key<>, string val1<>, int val2, float val3) =4;
        int delete_key(string key<>) = 5;
        int exist(string key<>) = 6;
        int num_items() = 7;
    }=1;
}=99;
