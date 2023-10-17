#include <iostream>
#include <vector>
#include <algorithm>

int coinChange(std::vector<int>& coins, int amount) {
    // Create a dp array and initialize it with amount+1 (which is a value larger than the maximum possible number of coins)
    std::vector<int> dp(amount + 1, amount + 1);
    
    // Base case: 0 coins are needed to make the amount 0
    dp[0] = 0;
    
    // For each amount from 1 to the target amount
    for (int i = 1; i <= amount; i++) {
        // For each coin denomination
        for (int coin : coins) {
            // If the coin value is less than or equal to the current amount
            if (coin <= i) {
                // Update the dp value for the current amount
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    // If dp[amount] has its initial value (amount+1), that means we can't make that amount with the given coins
    return dp[amount] <= amount ? dp[amount] : -1;
}

int main() {
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    
    std::cout << "Minimum number of coins required: " << coinChange(coins, amount) << std::endl;
    
    return 0;
}
