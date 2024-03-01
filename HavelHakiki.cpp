#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

int main() {
    int sequence, j;
    std::vector<int> ds;
    std::cout << "Enter a graph's degree sequence, separating each term with a space, and finishing with a '.': ";
    while (std::cin >> sequence) {
        ds.push_back(sequence);
    }
    sort(ds.begin(), ds.end(), std::greater<int>());
    std::cout << "The degree sequence is length " << ds.size() << ".\n";

    j = 1;
    std::cout << "The sorted degree sequence is: (";
    for (int i : ds) {
        if (j < ds.size()) {
            std::cout << i << ", ";
            j++;
        }
        else {
            std::cout << i << ")\n";
        }
    }

    bool admissible = true;
    bool debug = false;
    for (int i = 0; i < ds.size() + 2; i++) {
        // Get first term
        int term = ds[0];

        // Apply Havel-Hakimi algorithm
        if (term > ds.size() - 1) {
            admissible = false;
        }
        else {
            // Erase first term
            ds.erase(ds.begin());
            for (int i = 0; i < term; i++) {
                ds[i] -= 1;
                if (ds[i] < 0) {
                    admissible = false;
                    break;
                }
            }
        }

        // Break loop if inadmissable
        if (admissible == false) {
            std::cout << "This degree sequence is inadmissible and a simple graph does not exist.\n";
            break;
        }

        // Resort degree sequence after each loop
        sort(ds.begin(), ds.end(), std::greater<int>());

        // Check if first term is 0
        if (ds[0] == 0) {
            std::cout << "This degree sequence is admissible and a simple graph exists.\n";
            break;
        }

        // Debug for checking the degree sequence
        if (debug) {
            // Print the degree sequence at each step if it is still admissible
            j = 1;
            std::cout << "The sorted degree sequence is now: (";
            for (int i : ds) {
                if (j < ds.size()) {
                    std::cout << i << ", ";
                    j++;
                }
                else {
                    std::cout << i << ")\n";
                }
            }
        }
    }
    return 0;
}
