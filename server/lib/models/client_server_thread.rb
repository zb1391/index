class ClientServerThread

  attr_reader :state, :client, :message
  
  def initialize(client)
    @client = client
    @state = states[:verify]
  end

  def get_client_data
    msg = @client.gets
    @message = eval(msg) 
  end

  def client_loop
    loop do
      get_client_data
      case @state
        when states[:verify]
          # do stuff
          puts "#{@message}".yellow
        else
          return
      end
    end
  end
  private

  def states
    @states ||= {
      verify: "VerifyCredentials"
    }
  end
end
