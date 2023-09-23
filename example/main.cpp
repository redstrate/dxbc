#include <iostream>

#include <dxbc_module.h>
#include <log/log.h>

#include <spirv_cross/spirv_glsl.hpp>

dxvk::Logger dxvk::Logger::s_instance("dxbc.log");

int main(int argc, char *argv[]) {
  // pass in the DXVK binary you want to decompile
  const std::string inputFile = argv[1];
  std::ifstream infile(inputFile, std::ios_base::binary);

  std::vector<char> buffer((std::istreambuf_iterator<char>(infile)),
                           std::istreambuf_iterator<char>());

  dxvk::DxbcReader reader(buffer.data(), buffer.size());

  dxvk::DxbcModule module(reader);

  dxvk::DxbcModuleInfo info;
  auto result = module.compile(info, "test");

  spirv_cross::CompilerGLSL glsl(result.code.data(), result.code.dwords());

  spirv_cross::CompilerGLSL::Options options;
  options.version = 310;
  options.es = true;
  glsl.set_common_options(options);

  std::cout << glsl.compile() << std::endl;

  return 0;
}