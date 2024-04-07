import subprocess

from utils import ShellScript
import config


def test_no_options():
    script = ShellScript("simple_cmd/ls_no_arg.sh")
    return script.run_from_stdin() == script.run_from_stdin(use_ref=True)


def test_c_option():
    script = ShellScript("simple_cmd/ls_no_arg.sh")
    return script.run_from_str() == script.run_from_str(use_ref=True)


def test_pretty_print_option():
    script = ShellScript("simple_cmd/ls_no_arg.sh")
    return script.run_pretty_print_from_str() == script.run_pretty_print_from_str(use_ref=True)


def test_no_options_with_file():
    script = ShellScript("simple_cmd/ls_no_arg.sh")
    return script.run_from_file() == script.run_from_file(use_ref=True)


def test_c_option_with_file():
    cmd = config.EXE.copy() + ["-c", "echo", "whatever.sh"]
    exe = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    exe_status = exe.wait()
    assert exe_status == 1 and exe.stdout.read().decode("utf-8") == "" and exe.stderr.read().decode("utf-8") != ""


def test_pretty_print_option_with_file():
    script = ShellScript("simple_cmd/ls_no_arg.sh")
    assert script.run_pretty_print_from_file() == script.run_pretty_print_from_stdin(use_ref=True)


def test_pretty_print_c_options():
    cmd = config.EXE_PRETTY_PRINT.copy() + ["-c", "echo"]
    process = subprocess.Popen(cmd, stdout=subprocess.PIPE)
    assert process.wait() == 0 and process.stdout.read().decode("utf-8") == "echo"


def test_c_pretty_print_options():
    cmd = config.EXE.copy() + ["-c", "echo", "--pretty-print"]
    process = subprocess.Popen(cmd, stdout=subprocess.PIPE)
    assert process.wait() == 0 and process.stdout.read().decode("utf-8") == "echo"
