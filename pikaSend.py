import pika

connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
channel = connection.channel()
channel.queue_declare(queue='members')
message = 1

channel.basic_publish(exchange='',
                      routing_key='members',
                      body=message)
print(" [x] Sent", message)

connection.close()