import os
import subprocess

import config


class ShellScript:
    def __init__(self, path):
        self.path = path

    def run_from_stdin(self, use_ref: bool = False):
        cmd = config.REF_STDIN_ARG if use_ref else config.STDIN_ARG
        with open(self.path, "r") as file:
            process = subprocess.Popen(cmd, stdin=file, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        status = process.wait()
        return status, process.stdout.read().decode("utf-8"), process.stderr.read().decode("utf-8")

    def run_from_str(self, use_ref: bool = False):
        # TODO
        pass

    def run_from_file(self, use_ref: bool = False):
        # TODO
        pass


def get_shell_scripts(folder_path: str):
    scripts = []
    for file_name in os.listdir(folder_path):
        if file_name.endswith(".sh"):
            path = os.path.join(folder_path, file_name)
            scripts.append(ShellScript(path))
    return scripts
