#include <functional>
#include <string>
#include <iostream>
#include <fstream>
#include "/grading_dir/tests/extra/sha256.h"


using namespace std;

const std::string who_am_i();
const std::string filename = "/grading_dir/results/feedback/" + who_am_i() + " [merkle_open_position].txt";


std::vector<std::pair<std::string,std::string>> merkle_open_position(const std::vector<std::string>& list, std::function<std::string(std::string)> hash_function, const unsigned int i);

string halfSHA(string s) {
    string out = SHA256::hashString(s);
    return out.erase(32);
}



int main() {
    ofstream out_file(filename);


    double total_score = 12.0;
    double score = 0.0;
    const vector<string> test_vec1 {"a", "b", "c", "d", "e", "f", "g", "h" };
    const string test_vec1_merkle_256 = "03d17ec0ddabb9af008dce3964169c576491f112481ef00d1e1ed93f8ff36673";
    const string test_vec1_merkle_half = "1ffd0c8939c7931d7460efd1dd2d70a8";

    // Merkle proof for test_vec1[2] = "c"
    const vector<pair<string,string>> test_vec1_256_proof_of_2 = {
        {"L",test_vec1[2]},
        {"R","f451a61749c611ba0fa0e16c61831db44f38c611dff25879cf271a24c81a88b6"}, // SHA256::hashString("d3")
        {"L","09fc26616cb10a1249d12c2ce0837e194f90a0f737d474ae827e50be5fbcafe8"}, // SHA256::hashString( SHA256::hashString("a0") + SHA256::hashString("b1") )
        {"R","3b73ae5b262f6e0c074cb04d9487ecd34ca2058722deb80cae9576d8365218a5"}, // SHA256::hashString( SHA256::hashString(SHA256::hashString("e4") + SHA256::hashString("f5")) + SHA256::hashString(SHA256::hashString("g6") + SHA256::hashString("h7"))  )
    };

    const vector<pair<string,string>> test_vec1_half_proof_of_6 = {
        { "L", "g" },
        { "R", "f254a1e7d56840a4f2faa65b43f82d21" },
        { "L", "f0d49b1d168674be1b3d0f30ee13de34" },
        { "L", "2a2c9976cbbc7ed980baaa12fbc46716" }
    };

    const vector<string> test_vec2 = {"hello", "world!"};
    const string test_vec2_merkle_256 = "45bc2c583b1d8ebb501fcc2f29d0330f316649bbf23d76feee22b64e6b67972b";
    const string test_vec2_merkle_half = "0ba2041589c36203f056601e192947cd";

    const vector<pair<string,string>> test_vec2_256_proof_of_1 = {
        {"R", test_vec2[1]},
        {"L", "5a936ee19a0cf3c70d8cb0006111b7a52f45ec01703e0af8cdc8c6d81ac5850c"}
    };


    const vector<pair<string,string>> test_vec2_half_proof_of_0 = {
        { "L", "hello" },
        { "R", "c0bfd208da32a445ed203a9ae135b9c8" }
    };


    const vector<string> test_vec3 = {"Merkle", "trees", "are", "cool!"};
    const string test_vec3_merkle_256 = "4683d51abcd4e5b01faec86dd4efaca78e669176d10a3f047c90790bab793cc2";
    const string test_vec3_merkle_half = "14eb2595cea11252834f25a78952182b";


    const vector<pair<string,string>> test_vec3_256_proof_of_3 = {
        {"R", test_vec3[3]},
        {"L", "07b83ebd03651aa06a3e788f04cf1875a063005f2bece50e46cd8d3736bfa23d"},
        {"L", "d60697595896c2a90bcffa77d76dd7cd25b46034d7c7f2310b692c9d97d53624"}
    };


    const vector<pair<string,string>> test_vec3_half_proof_of_2 = {
        { "L", "are" },
        { "R", "04333f13cc8de118e6aa09a1f469dede" },
        { "L", "0f4b84ed9bcc94077da262798b09cc0d" }
    };


    const vector<string> test_vec4 = {"h", "g", "f", "e", "d", "c", "b", "a"};
    const string test_vec4_merkle_256 = "457b2d396de9a0d62eeee51d3712538c78ddf46c2ea37f80c5d6e4082e91d6ea";
    const string test_vec4_merkle_half = "caab89a6bbc2835daa87cd072601c8fb";


    const vector<pair<string,string>> test_vec4_half_proof_of_5 = {
        { "R", "c" },
        { "L", "af327a6478537246e0d9f0c589986d5f" },
        { "R", "c8ca66fc7a95ed864d1aa322f3aaccc0" },
        { "L", "6de8c23ee890de051881247ad57acdd0" }
    };

    const vector<pair<string,string>> test_vec4_256_proof_of_3 = {
        { "R", "e" },
        { "L", "e4ab4e3b1493d5a997b4e51cdefbaa10570ef3ea9432bd72e7b6a89654ceb7f6" },
        { "L", "38a57eb7695285f5327a68aa68da676334dbb6dd4962f2a6d484751b8d4683da" },
        { "R", "df474942ef15958d31f55cdedc4cc2a716110f897e57b5d7d04642cd492ce281" }
    };


    const vector<string> test_vec5 = { "a", "b", "a", "b", "c", "d", "c", "c"  };
    const string test_vec5_merkle_256 = "a08138cec293c15b913a4bbe9ccbf5d7db69a55d7afaeb1547ff8c8885cb1c92";
    const string test_vec5_merkle_half = "1e565f861926b528c7da93ffd1bc41f3";

    const vector<pair<string,string>> test_vec5_half_proof_of_7 = {
        { "R", "c" },
        { "L", "6db53c9d5a2ca72a85ddf3a681c0d956" },
        { "L", "e1c44f5f0b9debc9d78668f12914c987" },
        { "L", "5121dda9ea25a0066dc9160a190468f7" },
    };
    const vector<pair<string,string>> test_vec5_256_proof_of_6 = {
        { "L", "c" },
        { "R", "f28d5b0d6f8be0da8446dabe79044cb9ed0ffa3150a003936155409fe778b885" },
        { "L", "4e6aed21bf36c85171ce7737edcb4e93ed95d75fa725b39c057cbcbba6cdcf65" },
        { "L", "b3af2533cbd1752bb95c1545e43afee117d8c1fdab62139c37c661a5829da1a1" },
    };


    const vector<string> test_vec6 = { "Even a single element list should work!" };
    const string test_vec6_merkle_256 = "c35be5ab21dd6554f6200e933c3a5b085cd3b0e1cbad8b7e88bb1d91fabea4e8";
    const string test_vec6_merkle_half = "c35be5ab21dd6554f6200e933c3a5b08";

    const vector<pair<string,string>> test_vec6_256_proof_of_0 = {
        { "L", "Even a single element list should work!" },
    };

    const vector<pair<string,string>> test_vec6_half_proof_of_0 = {
        { "L", "Even a single element list should work!" },
    };


    vector<const vector<string>*> test_vecs = { &test_vec1, &test_vec2, &test_vec3, &test_vec4, &test_vec5, &test_vec6 };
    vector<const vector<pair<string,string>>* > test_vecs_256_proofs = { &test_vec1_256_proof_of_2, &test_vec2_256_proof_of_1, &test_vec3_256_proof_of_3, &test_vec4_256_proof_of_3, &test_vec5_256_proof_of_6, &test_vec6_256_proof_of_0 };
    vector<const vector<pair<string,string>>* > test_vecs_half_proofs = { &test_vec1_half_proof_of_6, &test_vec2_half_proof_of_0, &test_vec3_half_proof_of_2, &test_vec4_half_proof_of_5, &test_vec5_half_proof_of_7, &test_vec6_half_proof_of_0 };

    const vector<unsigned int> positions_256 = { 2, 1, 3, 3, 6, 0};
    const vector<unsigned int> positions_half = {6, 0, 2, 5, 7, 0};

    for(int i = 0; i < 6; ++i) {
        vector<pair<string,string>> proof256 = merkle_open_position(*test_vecs[i], SHA256::hashString, positions_256[i]);
        vector<pair<string,string>> half_proof = merkle_open_position(*test_vecs[i], halfSHA, positions_half[i]);
        if(proof256 == *test_vecs_256_proofs[i]) {
            ++score;
        }
        else {
            out_file << "test_vec" << to_string(i+1) << "256_proof_of_" << to_string(positions_256[i]) << " proof incorrect when using SHA256 hash" << endl;
        }
        if(half_proof == *test_vecs_half_proofs[i]) {
            ++score;
        }
        else {
            out_file << "test_vec" << to_string(i+1) << "half_proof_of_" << to_string(positions_half[i]) << " proof incorrect when using halfSHA hash" << endl;
        }
    }

    out_file.close();

    RESULT(100*(score/total_score));

    return 0;
}
