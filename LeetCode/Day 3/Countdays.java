import java.util.Arrays;

class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0])); // Sort meetings by start day

        int meetingDays = 0, lastEnd = 0;

        for (int[] meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // Count days without meetings between previous meeting end and current start
            if (start > lastEnd + 1) {
                meetingDays += (start - lastEnd - 1);
            }

            // Merge overlapping meetings
            lastEnd = Math.max(lastEnd, end);
        }

        // Count remaining free days after last meeting
        if (lastEnd < days) {
            meetingDays += (days - lastEnd);
        }

        return meetingDays;
    }
}
