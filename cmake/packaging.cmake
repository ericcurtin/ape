
find_program(rpmbuild_path "rpmbuild" FALSE)
if(rpmbuild_path)
  message(STATUS "rpmbuild found, enabling RPM for the 'package' target")
  list(APPEND CPACK_GENERATOR RPM)
else(rpmbuild_path)
  message(STATUS "The 'package' target will not build a RPM")
endif(rpmbuild_path)

find_program(dpkg_path "dpkg" FALSE)
if (dpkg_path)
  message(STATUS "dpkg found, enabling DEB for the 'package' target")
  list(APPEND CPACK_GENERATOR DEB)
else(dpkg_path)
  message(STATUS "The 'package' target will not build a DEB")
endif(dpkg_path)

set(CPACK_PACKAGE_NAME "ape")
set(CPACK_PACKAGE_CONTACT "ericcurtin17@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
"ape is a compiler wrapper that allows you to run compiled languages as scripting languages")

if(CPACK_GENERATOR)
    include(CPack)
endif()

