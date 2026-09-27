#include <functional>
#include <string>
#include <iostream>
#include <fstream>
#include "/grading_dir/tests/extra/sha256.h"


using namespace std;

const std::string who_am_i();
const std::string filename = "/grading_dir/results/feedback/" + who_am_i() + " [merkle_verify_full].txt";


int merkle_verify_full(const std::string root, const std::vector<std::string>& list, std::function<std::string(std::string)> hash_function);

string halfSHA(string s) {
    string out = SHA256::hashString(s);
    return out.erase(32);
}



int main() {
    ofstream out_file(filename);


    double total_score = 24.0;
    double score = 0.0;
    const vector<string> test_vec1 {"a", "b", "c", "d", "e", "f", "g", "h" };
    const vector<string> test_vec1_wrong {"a", "b", "c", "d", "e", "f", "g", "g" };
    const string test_vec1_merkle_256 = "03d17ec0ddabb9af008dce3964169c576491f112481ef00d1e1ed93f8ff36673";
    const string test_vec1_merkle_half = "1ffd0c8939c7931d7460efd1dd2d70a8";


    const vector<string> test_vec2 = {"hello", "world!"};
    const vector<string> test_vec2_wrong = {"hello", "world?"};
    const string test_vec2_merkle_256 = "45bc2c583b1d8ebb501fcc2f29d0330f316649bbf23d76feee22b64e6b67972b";
    const string test_vec2_merkle_half = "0ba2041589c36203f056601e192947cd";

    const vector<string> test_vec3 = {"Merkle", "trees", "are", "cool!"};
    const vector<string> test_vec3_wrong = {"Merkle", "trees", "are", "LAME"};
    const string test_vec3_merkle_256 = "4683d51abcd4e5b01faec86dd4efaca78e669176d10a3f047c90790bab793cc2";
    const string test_vec3_merkle_half = "14eb2595cea11252834f25a78952182b";

    const vector<string> test_vec4 = {"h", "g", "f", "e", "d", "c", "b", "a"};
    const vector<string> test_vec4_wrong = {"h", "g", "f", "e", "z", "c", "b", "a"};
    const string test_vec4_merkle_256 = "457b2d396de9a0d62eeee51d3712538c78ddf46c2ea37f80c5d6e4082e91d6ea";
    const string test_vec4_merkle_half = "caab89a6bbc2835daa87cd072601c8fb";


    const vector<string> test_vec5 = { "a", "b", "a", "b", "c", "d", "c", "c"  };
    const vector<string> test_vec5_wrong = { "a", "b", "%", "b", "c", "d", "c", "c"  };
    const string test_vec5_merkle_256 = "a08138cec293c15b913a4bbe9ccbf5d7db69a55d7afaeb1547ff8c8885cb1c92";
    const string test_vec5_merkle_half = "1e565f861926b528c7da93ffd1bc41f3";

    const vector<string> test_vec6 = { "Even a single element list should work!" };
    const vector<string> test_vec6_wrong = { "Even a single element list sh0uld work!" };
    const string test_vec6_merkle_256 = "c35be5ab21dd6554f6200e933c3a5b085cd3b0e1cbad8b7e88bb1d91fabea4e8";
    const string test_vec6_merkle_half = "c35be5ab21dd6554f6200e933c3a5b08";

    vector<const vector<string>*> test_vecs = { &test_vec1, &test_vec2, &test_vec3, &test_vec4, &test_vec5, &test_vec6 };
    vector<const vector<string>*> test_vecs_wrong = { &test_vec1_wrong, &test_vec2_wrong, &test_vec3_wrong, &test_vec4_wrong, &test_vec5_wrong, &test_vec6_wrong };
    vector<const string*> test_vecs_256_hash = { &test_vec1_merkle_256, &test_vec2_merkle_256, &test_vec3_merkle_256, &test_vec4_merkle_256, &test_vec5_merkle_256, &test_vec6_merkle_256 };
    vector<const string*> test_vecs_half_hash = { &test_vec1_merkle_half, &test_vec2_merkle_half, &test_vec3_merkle_half, &test_vec4_merkle_half, &test_vec5_merkle_half, &test_vec6_merkle_half };

    for(int i = 0; i < 6; ++i) {
        int res_256 = merkle_verify_full(*test_vecs_256_hash[i], *test_vecs[i], SHA256::hashString);
        int res_half = merkle_verify_full(*test_vecs_half_hash[i], *test_vecs[i], halfSHA);
        if(res_256 == 0) {
            ++score;
        }
        else {
            out_file << "test_vec" << to_string(i+1) << " full verify outputed != 0 but expected 0 when using SHA256 hash" << endl;
        }
        if(res_half == 0) {
            ++score;
        }
        else {
            out_file << "test_vec" << to_string(i+1) << " full verify outputed != 0 but expected 0 when using halfSHA hash" << endl;
        }
    }


    for(int i = 0; i < 6; ++i) {
        int res_256 = merkle_verify_full(*test_vecs_256_hash[i], *test_vecs_wrong[i], SHA256::hashString);
        int res_half = merkle_verify_full(*test_vecs_half_hash[i], *test_vecs_wrong[i], halfSHA);
        if(res_256 != 0) {
            ++score;
        }
        else {
            out_file << "test_vec" << to_string(i+1) << " full verify outputed 0 but expected != 0 when using SHA256 hash" << endl;
        }
        if(res_half != 0) {
            ++score;
        }
        else {
            out_file << "test_vec" << to_string(i+1) << " full verify outputed 0 but expected != 0 when using halfSHA hash" << endl;
        }
    }

    out_file.close();

    RESULT(100*(score/total_score));

    return 0;
}
