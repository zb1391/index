require 'rails_helper'

describe 'ClientServerThread' do
  before(:all) do
    @client_server_thread = ClientServerThread.new(nil)
  end

  describe 'initialize' do
    it 'sets state to "VerifyCredentials"' do
      expect(@client_server_thread.state).to eq("VerifyCredentials")
    end
  end
end
