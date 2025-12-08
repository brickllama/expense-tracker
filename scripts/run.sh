#!/bin/bash
clear
script_dir="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
root_dir="$(dirname "${script_dir}")"
build_dir="${root_dir}/build"

exe_dir="${build_dir}"
exe_name=""

while test $# -gt 0; do
    case "$1" in
        -t|--test)
            exe_dir="${build_dir}/tests"
            shift
            ;;
        -b|--backend)
            exe_name="BackendTests"
            shift
            ;;
        -f|--frontend)
            exe_name="FrontendTests"
            shift
            ;;
        *)
            echo "Unknown argument: $1"
            exit 1
            ;;
    esac
done

if [[ "$exe_dir" == "$build_dir" ]]; then
    exe_name="ExpenseTracker"
fi

full_exe_path="${exe_dir}/${exe_name}"

cd "$root_dir" || exit

if [[ ! -d "$build_dir" ]]; then
    rm -rf "$build_dir"
fi

mkdir -p "$build_dir" && cd "$build_dir" || exit

cmake --graphviz=dependency_graph.dot -G Ninja ..
ninja

"$full_exe_path"
