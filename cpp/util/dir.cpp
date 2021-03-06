// Copyright 2014-2014 the openage authors. See copying.md for legal info.

#include "dir.h"

#include "../log.h"

namespace openage {
namespace util {

Dir::Dir(std::string basedir) {
	this->basedir = basedir;
}

Dir::~Dir() {}

std::string Dir::join(const std::string &fname) const {
	return this->basedir + PATHSEP + fname;
}

Dir Dir::append(const std::string &suffix) {
	if (suffix.length() == 0) {
		return Dir{this->basedir};
	} else {
		return Dir{this->join(suffix)};
	}
}


std::string basename(const std::string &fullpath) {
	size_t rsep_pos = fullpath.rfind(PATHSEP);
	if (rsep_pos == std::string::npos) {
		return "";
	} else {
		return fullpath.substr(rsep_pos + 1);
	}
}


std::string dirname(const std::string &fullpath) {
	std::string ret;

	size_t rsep_pos = fullpath.rfind(PATHSEP);
	if (rsep_pos == std::string::npos) {
		ret = "";
	} else {
		ret = fullpath.substr(0, rsep_pos);
	}
	return ret;
}

} //namespace util
} //namespace openage
