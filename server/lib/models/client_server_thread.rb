class ClientServerThread
  attr_reader :state, :client
  
  def initialize(client)
    @state = states[:verify]
  end

  def get_client_data
    loop do
      case @state
        when states[:verify]
          # do stuff
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
