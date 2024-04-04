import os
import subprocess

import config


class ShellScript:
    def __init__(self, path):
        self.path = path

    def run_from_stdin(self, use_ref: bool = False):
        cmd = config.REF if use_ref else config.EXE
        with open(self.path, "r") as file:
            process = subprocess.Popen(cmd, stdin=file, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        status = process.wait()
        return status, process.stdout.read().decode("utf-8"), process.stderr.read().decode("utf-8")

    def run_from_str(self, use_ref: bool = False):
        cmd = config.REF + ["-c"] if use_ref else config.EXE + ["-c"]
        with open(self.path, "r") as file:
            cmd.append(file.read())
            process = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            file.close()
        status = process.wait()
        return status, process.stdout.read().decode("utf-8"), process.stderr.read().decode("utf-8")

    def run_from_file(self, use_ref: bool = False):
        cmd = config.REF + [self.path] if use_ref else config.EXE + [self.path]
        process = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        status = process.wait()
        return status, process.stdout.read().decode("utf-8"), process.stderr.read().decode("utf-8")


def get_shell_scripts(folder_path: str):
    scripts = []
    for file_name in os.listdir(folder_path):
        if file_name.endswith(".sh"):
            path = os.path.join(folder_path, file_name)
            scripts.append(ShellScript(path))
    return scripts
