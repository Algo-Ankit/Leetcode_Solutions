class Spreadsheet {
private:
    vector<vector<int>> grid;
    int rows;

    // Get value of either a cell reference or integer
    int getVal(const string &s) {
        if (isalpha(s[0])) { 
            int col = s[0] - 'A';
            int row = stoi(s.substr(1)) - 1;
            return grid[row][col];
        } else {
            return stoi(s);
        }
    }

public:
    // Initialize spreadsheet with r rows and 26 columns
    Spreadsheet(int r) {
        rows = r;
        grid.assign(rows, vector<int>(26, 0));
    }

    // Set the specified cell to a value
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    // Reset the specified cell to 0
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    // Evaluate a formula of the form "=X+Y"
    int getValue(string formula) {
        string content = formula.substr(1);
        int plusPos = content.find('+');
        string part1 = content.substr(0, plusPos);
        string part2 = content.substr(plusPos + 1);
        return getVal(part1) + getVal(part2);
    }
};


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */