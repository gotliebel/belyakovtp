FROM python:latest
RUN mkdir -p ./opt/techprog
EXPOSE 8898

RUN apt-get update
RUN apt-get install -y python3-pip python-dev cmake make build-essential
RUN useradd -ms ./bin/bash tp2022user
RUN cd ./opt/techprog
RUN mkdir -p build && cd build && cmake .. && make
RUN pip install flask argparse
COPY . ./opt/techprog

USER tp2022user
CMD python app.py --port 8898 --host "0.0.0.0"
