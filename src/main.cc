#include <bits/stdc++.h>
#include <cxxopts.hpp>

// TODO Switch to streams
bool readFile(const std::string &fpath, std::string &content) {
  std::ifstream ifs;
  ifs.open(fpath);
  if (!ifs.good()) {
    std::cerr << "Failed to open file: " << fpath << std::endl;
    return false;
  }
  content.assign(std::istreambuf_iterator<char>(ifs),
                 std::istreambuf_iterator<char>());
  return true;
}

class WcResult {
public:
  WcResult(size_t lines, size_t words, size_t chars)
      : lines(lines), words(words), chars(chars) {}
  size_t lines;
  size_t words;
  size_t chars;
  // TODO Remove below print method
  // - Printing will be handled in `main` to apply options
  std::string print() {
    std::stringstream ss;
    ss << lines << " " << words << " " << chars << " ";
    return ss.str();
  }
};

// TODO Switch to streams
WcResult wordCount(const std::string &content) {
  size_t lines = std::count(content.begin(), content.end(), '\n') + 1;
  // TODO Check all whiltespaces, not just spaces
  size_t words = std::count(content.begin(), content.end(), ' ') + 1;
  size_t chars = content.size();
  return WcResult(lines, words, chars);
}

int main(int argc, char const *argv[]) {
  cxxopts::Options opts("wcpp", "C++ version of the original wc tool");
  opts.add_options()("h,help", "Print help")("V,version", "Print version")(
      "f,file", "File path", cxxopts::value<std::string>());
  opts.add_options("Count Options")("l,lines", "count lines")(
      "w,words", "count words")("c,chars", "count characters");
  // TODO Handle multiple files
  opts.parse_positional({"file"});
  auto optRes = opts.parse(argc, argv);
  const auto isSet = [&optRes](const std::string &opt) {
    return optRes.count(opt) > 0;
  };
  if (isSet("help") || argc == 1) {
    std::cout << opts.help() << std::endl;
    return 0;
  }
  if (isSet("version")) {
    std::cout << "wcpp v0.1.0" << std::endl;
    return 0;
  }
  const auto fpath = optRes["file"].as<std::string>();
  std::string content;
  if (!readFile(fpath, content)) {
    return 1;
  }
  WcResult wcResult = wordCount(content);
  // TODO Add options
  std::cout << wcResult.print() << fpath << std::endl;
  return 0;
}
