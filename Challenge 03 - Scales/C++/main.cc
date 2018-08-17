#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

template<typename T> using V = std::vector<T>;

// Overload of left bitwise operator to "std::cout" vectors
template <typename T>
std::ostream& operator <<(std::ostream& os, V<T> v){
	if (v.size() > 0){
		os << v[0];
		for (int i = 1; i < v.size(); ++i){
			os << " " << v[i];
		}
	}
	return os;
}

// Overload of left bitwise operator to "std::cout" sets
template <typename T>
std::ostream& operator <<(std::ostream& os, std::set<T> s){
	if (s.size() > 0){
		typename std::set<T>::iterator it = s.begin();
		os << *it;
		it = next(it);
		while (it != s.end()){
			os << " " << *it ;
			++it;
		}
	}
	return os;
}

// Implementation of the modulo operator for negative numbers
inline int modulo(int a, int b) {
	const int result = a % b;
	return result >= 0 ? result : result + b;
}

const int kW = 2; // whole step (one tone)
const int kH = 1; // half step (one semitone)

const int kMajor = 0;
const int kMinor = 1;

const V<int> kMajorMode = {kW, kW, kH, kW, kW, kW, kH};
const V<int> kMinorMode = {kW, kH, kW, kW, kH, kW, kW};

const V<std::string> kNotes = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

// Function to create a major or minor scale given the tonal note and the mode
V<std::string> MakeScale(const std::string& tonal_note, int mode){
	V<std::string> out_scale;
	V<std::string>::const_iterator start_position = find(kNotes.begin(), kNotes.end(), tonal_note);
	if (start_position != kNotes.end()){
		int current_index = start_position - kNotes.begin();
		if (mode == kMajor){
			for (int i = 0; i < kMajorMode.size(); ++i) {
				out_scale.push_back(kNotes[current_index]);
				current_index = modulo(current_index + kMajorMode[i], kNotes.size());
			}
		}
		else if (mode == kMinor){
			for (int i = 0; i < kMinorMode.size(); ++i) {
				out_scale.push_back(kNotes[current_index]);
				current_index = modulo(current_index + kMinorMode[i], kNotes.size());
			}
		}
		else {
			std::cout << "Wrong mode!" << std::endl;
		}
	}
	else {
		std::cout << "Wrong note!" << std::endl;
	}
	return out_scale;
}

// Map containing the tonalities as keys and the scales as values
struct TonalMap{
	static std::map<std::string, V<std::string>> BuildMap(){
		std::map<std::string, V<std::string>> m;
		for (V<std::string>::const_iterator it = kNotes.begin(); it != kNotes.end(); ++it){
			for (int i = 0; i < 2; ++i){
				std::string tonality;
				if (i == 0){
					tonality = "M" + *it;
				}
				else if (i == 1){
					tonality = "m" + *it;
				}
				m[tonality] = MakeScale(*it, i);
			}
		}
		return m;
	 }
};

const std::map<std::string, V<std::string>> kScales = TonalMap::BuildMap();

// Given a note returns its sharp version if the given note is flat
std::string FixFlatsNShaps(const std::string& in_note){
	if (in_note.length() == 2){
		std::string note(1, in_note[0]);
		char alteration = in_note[1];
		V<std::string>::const_iterator original_pos = find(kNotes.begin(), kNotes.end(), note);
		int original_index = original_pos - kNotes.begin();
		if (alteration == 'b'){
			return kNotes[modulo((original_index - 1), kNotes.size())];			
		}
		else if (alteration == '#' && (note == "B" || note == "E")){
			return kNotes[modulo((original_index + 1), kNotes.size())];			
		}
	}
	return in_note;
}

// Returns the possible tonalities matching a given a set of notes
V<std::string> GetTonalities(const std::set<std::string>& in_notes){
	V<std::string> possible_tonalities;
	for (std::map<std::string, V<std::string>>::const_iterator m_it = kScales.begin(); m_it != kScales.end(); ++m_it){
		bool found;
		for (std::set<std::string>::const_iterator s_it = in_notes.begin(); s_it != in_notes.end(); ++s_it){
			found = find(m_it->second.begin(), m_it->second.end(), *s_it) != m_it->second.end();
			if (!found) break;
		}
		if (found){
			possible_tonalities.push_back(m_it->first);
		}
	}
	if (possible_tonalities.empty()){
		possible_tonalities.push_back("None");		
	}

	return possible_tonalities;
}

int main(){
    int c;
    std::cin >> c;
    for (int i = 1; i <= c; ++i){
        int n;
        std::cin >> n;
        std::set<std::string> in_notes;
        std::set<std::string> translated_notes;
        for (int j = 0; j < n; ++j){
        	std::string note;
        	std::cin >> note;
        	in_notes.insert(note);
        	translated_notes.insert(FixFlatsNShaps(note));
        }
        std::cout << "Case #" << i << ": " << GetTonalities(translated_notes) << std::endl;
    }
    return 0;
}