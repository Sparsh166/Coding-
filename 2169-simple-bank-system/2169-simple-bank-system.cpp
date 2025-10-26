class Bank {
private: 
    unordered_map<int, long long> bank;  // store account → balance
    int n;
public:
    Bank(vector<long long>& balance) {
        this->n = balance.size();
        unordered_map<int,long long>bank;
        for(int i=0;i<n;i++){
            this->bank[i+1] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1<=n && account2<=n && this->bank[account1]>= money){
            this->bank[account1]-= money;
            this->bank[account2]+= money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account<=n){
            this->bank[account]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account<=n && this->bank[account]>=money){
            this->bank[account]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */