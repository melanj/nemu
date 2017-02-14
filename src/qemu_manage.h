#ifndef QEMU_MANAGE_H_
#define QEMU_MANAGE_H_

#include <string>
#include <thread>
#include <cstdint>
#include <vector>
#include <map>
#include <atomic>
#include <unordered_set>
#include <memory>
#include <limits.h>
#include <form.h>
#include <ncurses.h>
#include <sqlite3.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#define _(str) gettext(str)
#define STRING_LITERAL(x) # x
#define STRING(x) STRING_LITERAL(x)
#define VERSION "0.1.8"
#define DEFAULT_NETDRV "virtio"

namespace QManager
{
  extern const char *YesNo[3];
  extern const char *NetDrv[4];
  extern std::atomic<bool> finish;

  typedef std::vector<std::string> VectorString;
  typedef std::map<std::string, std::string> MapString;
  typedef std::map<std::string, std::vector<std::string>> MapStringVector;

  enum input_choices {
    MenuVmlist = 1, MenuAddVm = 2,
    MenuKeyEnter = 10,
    MenuKeyR = 114, MenuKeyC = 99,
    MenuKeyF = 102, MenuKeyD = 100,
    MenuKeyE = 101, MenuKeyL = 108,
    MenuKeyY = 121, MenuKeyA = 97,
    MenuKeyI = 105, MenuKeyS = 115,
  };

  template <typename T>
  struct guest_t {
    T name, arch, cpus, memo,
    disk, vncp, imac, kvmf,
    hcpu, path, ints, usbp,
    usbd, ndrv, install;
  };

  class QMException : public std::exception {
    public:
      QMException(const std::string &m) : msg(m) {}
      ~QMException() throw() {}
      const char* what() const throw() { return msg.c_str(); }

    private:
      std::string msg;
  };
} // namespace QManager

#endif