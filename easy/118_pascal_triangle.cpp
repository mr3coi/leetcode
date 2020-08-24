class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		std::vector<std::vector<int>> output;
		if (numRows > 0) {
			output.emplace_back(std::initializer_list<int>{1});
			for (int row=1;row<numRows;++row) {
				std::vector<int> rowVector;
				rowVector.reserve(row+1);
				const std::vector<int>& lastRow = output.back();
				rowVector.push_back(lastRow.at(0));
				for (int col=1;col<row;++col) rowVector.push_back(lastRow.at(col-1) + lastRow.at(col));
				rowVector.push_back(lastRow.at(row-1));
				output.emplace_back(std::move(rowVector));
			}
		}
		return output;
	}
};
