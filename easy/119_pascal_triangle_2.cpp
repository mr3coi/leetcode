class Solution {
public:
	vector<int> getRow(int rowIndex) {
		std::vector<int> buffer0{1}, buffer1{1,1};
		if (rowIndex == 0) return buffer0;
		if (rowIndex == 1) return buffer1;

		buffer0.resize(rowIndex+1,0);
		buffer1.resize(rowIndex+1,0);
		std::vector<int> *src, *dest;
		for (int row=2;row<=rowIndex;++row) {
			if (row % 2 == 0) {
				src  = &buffer1;
				dest = &buffer0;
			}
			else {
				src  = &buffer0;
				dest = &buffer1;
			}
			dest->at(0) = src->at(0);
			for (int col=1;col<=row;++col) {
				dest->at(col) = src->at(col) + src->at(col-1);
			}
		}
		return (rowIndex % 2 == 0 ? buffer0 : buffer1);
	}
};
