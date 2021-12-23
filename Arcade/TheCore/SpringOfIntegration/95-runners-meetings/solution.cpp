int solution(vector<int> startPosition, vector<int> speed) {
    int maxMeetingCount = -1;
    for (int i = 0; i < startPosition.size()-1; i++) {
        map<double, int> dict;
        for (int j = i+1; j < startPosition.size(); j++) {
            if (speed[i] == speed[j] && startPosition[i]==startPosition[j]) continue;
			double m = (startPosition[i]-startPosition[j])/((speed[j]-speed[i])/60.0);
			if (m >= 0) {
				if (!dict[m]) dict[m] = 2;
				else dict[m]++;
			}
        }
        for (auto d : dict) {
            maxMeetingCount=max(maxMeetingCount, d.second);
        }
    }
    return maxMeetingCount >= 2 ? maxMeetingCount : -1;
}
