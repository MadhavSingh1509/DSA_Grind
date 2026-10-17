
class BusBooking {
private:
    vector<vector<int>> cost;
    int totalTime;
    int bookedCount;

public:
    BusBooking(int n) {
        cost.assign(n + 1, vector<int>(4, 0));
        totalTime = 0;
        bookedCount = 0;
    }

    void toggle(string seat) {
        int col = seat[0] - 'A';
        int row = stoi(seat.substr(1));

        // Non-zero cost means the seat is already booked.
        if (cost[row][col] != 0) {
            totalTime -= cost[row][col];
            cost[row][col] = 0;
            bookedCount--;
            return;
        }

        int time = 1;

        // A is adjacent to B.
        if (col == 0 && cost[row][1] != 0) {
            time = 3;
        }

        // D is adjacent to C.
        if (col == 3 && cost[row][2] != 0) {
            time = 3;
        }

        cost[row][col] = time;
        totalTime += time;
        bookedCount++;
    }

    int getTotalTime() {
        return totalTime;
    }

    int getMinTime() {
        return bookedCount;
    }
};
