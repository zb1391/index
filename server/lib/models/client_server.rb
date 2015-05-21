class ClientServer
  attr_reader :windows_server, :is_listening, :signed_in_users

  def initialize(signed_in_users = {})
    @signed_in_users = signed_in_users
    @windows_server = TCPServer.open(ENV["WINDOWS_PORT"].to_i)
    Thread.start{listen_for_clients}
  end

  def listen_for_clients
    @is_listening = true
    loop do
      Thread.start(windows_server.accept) do |client|
        create_client_thread
      end
    end
    @is_listening = false
  end

  private

  def create_client_thread(client)
    puts 'CONNECTED'.green
    client_server_thread = ClientServerThread.new(client) 
    client.close
  end
end
