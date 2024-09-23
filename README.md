# WSL 환경 구성
```bash
# Linux update
sudo apt-get update -y
sudo apt-get upgrade -y

# g++, gdb 설치
sudo apt-get install build-esential gdb -y

# c++20을 사용하기 위해서 g++-13 이상을 사용해야 함
# - 위 명령어에서 설치가 안됐으면 Toolchain PPA를 추가한 후에 설치해야 함
# - `sudo add-apt-repository ppa:ubuntu-toolchain-r/test` 실행 안될 경우
#     - error message: sudo: add-apt-repository: command not found
#     - apt 서버를 추가할 수 없다는 것, `add-apt-repository` 명령어는 `software-properties-common` 패키지의 일부이기 때문에 해당 패키지를 설치해야 함
#     - `sudo apt-get install software-properties-common -y` 명령어 실행한 후에 다시 시도
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update -y
sudo apt-get install g++-13 -y
```

# c_cpp_properties.json
- C/C++ Extention의 설정 파일
- vscode에서 어떤 컴파일러를 사용할 것인지 설정
- UI, Json을 통해서 설정 가능
- [/docs/cpp/c-cpp-properties-schema-reference](https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference)

```json
// c_cppproperties.json
{
    "env"                                       :{},    // 표준 환경 변수 구문을 통해 구성에서 대체할 수 있는 사용자 정의 변수 배열
    "configurations":                                   // IntelliSense 엔진에 프로젝트와 기본 설정에 대한 정보를 제공하는 구성 객체 배열
    [
        {
            "name"                              : "",   // 구성을 식별하는 이름 (예: Linux, Mac, Win32)
            "compilerPath"                      : "",   // (선택) 프로젝트를 빌드하는 컴파일러의 전체 경로 (예: `/usr/bin/gcc`: IntelliSense를 보다 정확하게 활성화하기 위해 사용)
            "compilerArgs"                      : [],   // (선택) include 또는 defines를 수정하기 위한 컴파일러 인수 (예: "-m32")
            "intelliSenseMode"                  : "",   // MSVC, gcc 또는 Clang의 아키텍처별 변형에 매핑되는 IntelliSense 모드 설정하지 않으면 `${default}`로 설정됨
            "includePath"                       : [],   // 프로젝트에 포함시킬 헤더 파일이 들어있는 폴더의 경로
            "defines"                           : [],   // 파일을 구문 분석하는 동안 IntelliSense 엔진이 사용할 전처리기 정의 목록
            "cStandard"                         : "",   // IntelliSense에 사용할 C 언어 표쥰 버전
            "cppStandard"                       : "",   // IntelliSense에 사용할 C++ 언어 표준 버전
            "configurationProvider"             : "",   // 소스 파일에 대한 IntelliSense 구성 정보를 제공할 수 있는 VS Code의 확장 ID
            "windowsSdkVersion"                 : "",   // Windows SDK 버전
            "macFrameworkPath"                  : "",   // Mac 프레임워크에서 포함된 헤더를 검색하는 동안 IntelliSense 엔진이 사용할 경로 (macOS 구성에서만 지원)
            "forcedInclude"                     : [],   // (선택) 소스 파일의 다른 문자가 처리되기 전에 포함되어야 하는 파일 목록
            "compileCommands"                   : "",   // (선택) 작업 공간의 파일에 대한 전체 경로
            "dotConfig "                        : "",   // Kconfig 시스템이 만든 .config 파일에 대한 경로
            "mergeConfigurations"               : true, // 구성 공급자의 포함 경로, 정의 및 강제 포함과 포함 경로를 병합하도록 설정
            "customConfigurationVariables"      : {},   // launch.json 또는 tasks.json의 입력 변수에 사용할 `${cpptools:activeConfigCustomVariable}` 명령을 통해 쿼리할 수 있는 사용자 지정 변수
            "browse":                                   // `"C_Cpp.intelliSenseEngine"`이 `"Tag Parser"`(`"fuzzy"` IntelliSense 또는 `"browse"` 엔진이라고도 함)로 설정될 때 사용되는 속성 집합
            {
                "path"                          : [],   // 소스 파일에 포함된 헤더를 검색하기 위한 태그 파서의 경로 목록
                "limitSymbolsToIncludeHeaders"  : true, // true인 경우 태그 파서는 소스 파일에 의해 직접 또는 간접적으로 포함된 코드 파일만 파싱
                "databaseFilename"              : "",   // 생성된 심볼 데이터베이스 경로
            },   
        }
    ],
    
    "version"                                   : 4,    // 건들지 말 것
    "enableConfigurationSquiggles"              : true  // c_cpp_properties.json 파일에서 감지된 오류를 C/C++ 확장자에 보고하려면 true로 설정
}
```

# tasks.json
- [팔만코딩경-.vscode의 tasks.json 이해해보기](https://80000coding.oopy.io/93593d7e-617f-412e-9615-8051bd16104f)

# launch.json
- [/docs/cpp/launch-json-reference](https://code.visualstudio.com/docs/cpp/launch-json-reference)
- [팔만코딩경-.vscode의 launch.json 이해해보기](https://80000coding.oopy.io/35e98af5-73df-4c4c-947d-5ceb8848c361#35e98af5-73df-4c4c-947d-5ceb8848c361)