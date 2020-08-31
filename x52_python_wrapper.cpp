#ifdef PYBIND_BUILD
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include <pybind11/functional.h>

#include "dependencies/x52/x52/stdafx.h"
#include "dependencies/x52/x52/X52.h"

namespace py = pybind11;
using namespace pybind11::literals;

PYBIND11_MODULE(_x52, m) {

    m.doc() = "rafls fun lib";

    py::class_<X52Page>(m, "X52Page", "Class used to represent single \"pages\" on the MFD.")
        // Constructors
        .def(py::init<>())
        .def(py::init<bool>(), "interactive"_a)
        .def(py::init<
            std::tuple<std::string, std::function<void()>>,
            std::tuple<std::string, std::function<void()>>,
            std::tuple<std::string, std::function<void()>>
            >(), "top"_a, "mid"_a, "bot"_a)
        .def(py::init<
            std::tuple<std::string, std::function<void()>>,
            std::tuple<std::string, std::function<void()>>,
            std::tuple<std::string, std::function<void()>>,
            bool
            >(), "top"_a, "mid"_a, "bot"_a, "interactive"_a)
        
        // Getters
        .def("is_interactive", &X52Page::is_interactive, R"doc(
            Returns True if the page is interactive, else False.
        )doc")
        .def("get_text_top", &X52Page::get_text_top, R"doc(
            Returns the text stored in the top line as a str.
        )doc")
        .def("get_text_mid", &X52Page::get_text_mid, R"doc(
            Returns the text stored in the mid line as a str.
        )doc")
        .def("get_text_bot", &X52Page::get_text_bot, R"doc( 
            Returns the text stored in the bot line as a str.
        )doc")

        // Setters
        .def("set_text_top", &X52Page::set_text_top, "text"_a, R"doc( 
            Changes the text displayed in the top line.
            
            Keyword arguments:
            text -- the text to apply
        )doc")
        .def("set_text_mid", &X52Page::set_text_mid, "text"_a, R"doc( 
            Changes the text displayed in the mid line.
            
            Keyword arguments:
            text -- the text to apply
        )doc")
        .def("set_text_bot", &X52Page::set_text_bot, "text"_a, R"doc( 
            Changes the text displayed in the bot line.
            
            Keyword arguments:
            text -- the text to apply
        )doc")

        // Operator overloads
        .def(py::self == py::self)
    ;

    py::class_<X52Device>(m, "X52Device", "Class used to represent a single Device.")
        .def(py::init<void*, void*>())
        .def("page_add", &X52Device::page_add, "page"_a)
        .def("drawPage", &X52Device::drawPage)
        ;

    py::class_<X52>(m, "X52", R"doc(
            Class used to represent the entire interface of the module.

            An initialized instance of this class needs exist at all times,
            if any functionality of this module wants to be used.
        )doc")
        .def(py::init<>())
        .def("init", &X52::init, R"doc(
            This initializes the driver and is necessary in order to communicate with the device!
        )doc")
        .def("device_get", &X52::device_get)
        .def("get_x52devices", &X52::get_x52devices, R"doc(
            Returns all detected Devices as X52Devices.
        )doc")
    ;

    py::module utils = m.def_submodule("utils", "Utility functions");
    utils.def("current_time_millis", &current_time_millis, "Returns the passed millis since epoch");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
#endif // PYBIND_BILD